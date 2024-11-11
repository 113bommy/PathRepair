n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
count1=0
for i in range(1,len(l)):
       count=l[i]-l[i-1]
       if(count>count1):
              count1=count
x=max(count1/2,l[0],k-l[-1])
print("{:.10f}".format(x))