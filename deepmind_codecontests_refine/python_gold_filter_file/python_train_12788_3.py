A,B,C,D,E,F=map(int,input().split())
weight=100*A
suger=0
c=0
for i in range(F//(100*A)+1):
    for j in range(F//(100*B)+1):
        for k in range((i*A+j*B)*E//C+1):
            for l in range((i*A+j*B)*E//D+1):
                if 100*(i*A+j*B)+k*C+l*D<=F and k*C+l*D<=(i*A+j*B)*E and (i*i+j*j+k*k+l*l)!=0 and (k*C+l*D)/(100*(i*A+j*B)+k*C+l*D)>c:
                    c=(k*C+l*D)/(100*(i*A+j*B)+k*C+l*D)
                    weight=100*(i*A+j*B)+k*C+l*D
                    suger=k*C+l*D


print("{} {}".format(weight,suger))
