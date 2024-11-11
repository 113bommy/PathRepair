for _ in[0]*int(input()):
 x,y,r,s,t,u=map(float,input().split())
 d=((x-s)**2+(y-t)**2)**.5
 print([[[1,-2][d<u-r],[1,2][d<r-u]][r>u],0][r+u<d])
