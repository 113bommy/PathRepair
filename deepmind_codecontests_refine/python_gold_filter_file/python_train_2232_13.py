a=[int(x) for x in input().split()]
s=input()
cal=0
for i in s:
    i=int(i)
    cal+=a[i-1]
print(cal)