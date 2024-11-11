n,m,k=map(int,input().split())
l=list(map(int,input().split()))
sec=0
maxi=0
for i in range(n):
      if(l[i]>maxi):
            sec=maxi
            maxi=l[i]
      elif(l[i]>sec):
            sec=l[i]
t=m//(k+1)
man=(k*maxi + sec)*t + (m-((k+1)*t))*maxi
print(man)

