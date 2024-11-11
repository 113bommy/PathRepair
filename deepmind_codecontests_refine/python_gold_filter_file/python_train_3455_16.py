n,k = map(int,input().split())
s = list(input())
if n == 1 and k:
    print (0)
    exit()
if k == 0:
    print ("".join(s))
    exit()
if int(s[0])>1:
    k-=1
s[0] = "1"
for i in range(1,n):
    if k == 0:
        break
    if s[i] != "0":
        s[i] = "0"
        k-=1
 
print ("".join(s))