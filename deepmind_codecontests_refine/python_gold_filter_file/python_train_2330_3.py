n,t = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

z,c = 0,0

for i in range(n):

    if (z+arr[i])<=t:
        z = z + arr[i]
        c+=1
    else:
        break

l = 0
r = c

if c==n:
    print(c)
    exit()

read = []
read.append(c)
aa=0
for i in range(1,n):
    z = z - arr[l]
    l+=1
    c-=1
    #print(r,aa)
    for j in range(r,n):
        if (z+arr[j])<=t:
            z = z + arr[j]
            c+=1
            aa = j
            if j==n-1:
                aa = j+1
        else:
            aa = j
            break
    read.append(c)
    r = aa
    #print(r)
#print(read)
print(max(read))