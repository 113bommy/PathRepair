a,b,c,d = map(int,input(). split())
if  (a+b+c-2*min(a,b,c)-max(a,b,c))>= d and (-(a+b+c)+2*max(a,b,c)+min(a,b,c))>=d :
    print(0)
elif max(a,b,c)>=(a+b+c+d-min(a,b,c))/2 :
    print(2*min(a,b,c)+d+max(a,b,c)-(a+b+c))
else :
    print(min(a,b,c)-max(a,b,c)+2*d)