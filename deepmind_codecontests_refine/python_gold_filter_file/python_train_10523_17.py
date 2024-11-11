while 1:
 m,f,r=map(int,input().split());s=m+f
 if m==f==r<0:break
 if m*f<-1 or s<30:print('F')
 elif s<50 and r<50:print('D')
 elif s<65:print('C')
 elif s<80:print('B')
 else:print('A')