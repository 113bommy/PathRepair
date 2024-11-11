n=int(input())
m=n//7
r=n%7
print(str(2*m+max(0,r-5))+' '+str(2*m+min(r,2)))