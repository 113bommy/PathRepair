


n = int(input())
a = []
_2 = [1]

FS = lambda x : x in S

def F(x):
   l,r=0,len(a)-1
   while l<r-1 :
      mid = (l+r)>>1
      if a[mid]==x :
         return True
      elif a[mid]<x:
         l = mid+1
      else :
         r = mid-1
   else :
      return a[l]==x or a[r]==x



for i in range(30):
   _2.append(_2[i]*2)
#for i in _2:
#   print(i)

for i in map(int,input().split()):
   a.append(i)
#a.sort()
S = set(a)
#for i in a:
#   print(i)


ans = 1
A = [0,a[0],0]

for i in a:
   if ans == 3 :
      break
   for j in _2:
      if ans == 3:
         break;
      if FS(i-j) :
         if ans<=2 :
            ans = 2
            A[0] = i-j
            A[1] = A[2] = i
         if FS(i+j):
            ans = 3
            A[2] = i+j
 #           print("ans is ",i,j)
            break
print(ans)
if(ans==3):
   print(*A)
else :
   print(A[1],end=" ")
   if(ans==2):
      print(A[0]+A[2]-A[1])
   else :
      print()
