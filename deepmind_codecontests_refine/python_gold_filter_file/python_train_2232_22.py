a = input().split()
b = list(input())
res = 0
#print(a,b)
for i in b:
    res = res + int(a[int(i)-1])
print(res)