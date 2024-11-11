n = int(input())
a = []
for i in range(n, n-100, -1):
    temp = i
    ans = temp
    while(temp>0):
        ans += temp%10
        temp = temp//10
    if ans == n:
        a.insert(0,i)
print(len(a))
for x in a:
    print(x)
