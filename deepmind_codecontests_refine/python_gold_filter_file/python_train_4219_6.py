n = int(input())
m = int(input())
l=[]
for i in range(n):
    l.append(int(input()))
l.sort(reverse=True)
s = 0
for i in l:
    if(m>0):
        m = m-i
        s = s + 1
    else:
        break
print(s)