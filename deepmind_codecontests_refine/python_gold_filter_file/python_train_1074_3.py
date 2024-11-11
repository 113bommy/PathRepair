input()
l=sorted(map(int,input().split()))
t=1
total=0
pi=3.1415926536
for i in l:
    total+=pi*i**2*t
    t*=-1
print(abs(total))