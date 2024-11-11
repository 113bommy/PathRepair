n, m = map(int,input().split())
a = list(map(int,input().split()))
b = []
count = 0


for i in range(len(a)-1):
    if a[i] != a[i+1]:
        count+=1
        b.append(count)
    else:
        count = 0
        b.append(count)


#print(b)
if len(b) == 0:
    print(n)
#elif max(b) == 0:
    #print(0)
else:
    print(max(b) + 1)
