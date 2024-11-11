n,m = map(int,input().split())
s = input()
t = input()
maxi = 0
maxin = []
for i in range(m-n+1):
    count = 0
    temp = []
    for j in range(n):
        if s[j] == t[i+j]:
            count += 1
        else:
            temp.append(j+1)
    if count >= maxi:
        maxi = count
        maxin = temp
print(n-maxi)
s = ""
for i in maxin:
    s += str(i) + " "
print(s[:-1])
