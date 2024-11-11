while 1:
 m,f,r=map(int,input().split());s=m+f
 if m==f==r==-1:break
 if m==-1 or f==-1 or s<30:print('F')
 elif s>79:print('A')
 elif s>64:print('B')
 elif s>49 or r>49:print('C')
 else:print('D')