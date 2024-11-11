n = int(input())
s = input()
l = list(map(int,input().split()))
s1 =''
for i in range(n):
    if (l[int(s[i]) - 1] <= int(s[i])):
        s1 =s1 + s[i]
    if(l[int(s[i])-1]>int(s[i])):
        while(i<n and l[int(s[i])-1]>=int(s[i])):
            s1 = s1+str(l[int(s[i])-1])
            i = i+1
        break
if len(s1)==n:
    print(s1)
else:
    for i in range(i,n):
        s1 = s1 +s[i]
    print(s1)