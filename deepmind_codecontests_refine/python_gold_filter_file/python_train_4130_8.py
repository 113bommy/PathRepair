n=input()
s=list(map(int,input().split()))
for i in s[-1::-1]:
    while s.count(i)-1:
        s.remove(i)
print(len(s))
for i in s:
 print(i,end=' ')