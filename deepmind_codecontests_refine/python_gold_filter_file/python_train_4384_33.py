w,h,k=map(int,input().split())

p=0
for i in range(k):
    o=((w-(4*i))*(h-(4*i)))-((w-(4*i)-2)*(h-(4*i)-2))
    p+=o
print (p)
