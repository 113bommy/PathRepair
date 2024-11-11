import math
def posible(str1 , str2 , mid , n , m , R):
    coun = 0
    cur = 0
    for i in range(n-mid+1):
        rang = i + mid
        if((cur+R[rang]) >= m):
            return True
        if(str1[i]==str2[cur]):
            cur += 1
    return False


str1 = input()
str2 = input()

n = len(str1)
m = len(str2)
R = []
r = m-1
l = n-1
coun = 0
for i in range(n):
    R.append(0)
R.append(0)
while(l>=0):
    if(r >=0 and str1[l] == str2[r]):
        r -= 1
        coun += 1
    R[l] = coun
    l -= 1
lo = 0
hi = n-1
ans = 0
while(lo <= hi):
    mid = math.floor((lo + hi)/2)
    if(posible(str1,str2,int(mid),n,m,R)):
        ans = mid
        lo = mid + 1
    else:
        hi = mid - 1
print(ans)
