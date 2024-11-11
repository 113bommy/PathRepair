b,k = map(int, input().split())
l=list(map(int, input().split()))

if b%2==0:
   if l[k-1]%2==0:
      print("even")
   else:
      print("odd")
   exit(0)


od_count=0

for x in l:
   if x%2!=0:
      od_count+=1

if od_count%2==0:
   print("even")
else:
   print("odd")



