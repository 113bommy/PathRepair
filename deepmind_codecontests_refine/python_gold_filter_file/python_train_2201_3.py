t=0
for i in 0,0:
    h,m=map(int,input().split(':'));t+=60*h+m
print(f'{t//120:02}:{t//2%60:02}')