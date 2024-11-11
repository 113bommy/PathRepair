n = int(input())
a = list(map(int,input().split()))
a.sort()
i = 1
j = 1
count = 0
while(j<=n):
    if a[j-1]>=i:
        count+=1
        #print(a[i-1])
        i+=1
    j+=1
print(count)