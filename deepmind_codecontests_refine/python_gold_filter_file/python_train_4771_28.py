n=int(input())
a=100000
for i in range(n+1):
    j=n-i
    count=0
    while i>0:
        count+=i%6
        i//=6
    while j>0:
        count+=j%9
        j//=9
    a=min(a,count)
print(a)
