n = int (input())
a = list(map(int , input().split()))
b = list(map(int , input().split()))
 
a= list(map(lambda x1, x2 : x1-x2, a,b))
a.sort() 
p1 = 0 
p2 = n-1
c= 0 
while(p1<p2) :
            if ((a[p1] +a[p2])> 0 ) : 
                        c+=(p2-p1)
                        p2-=1 
            else : p1+= 1 
print(c) 