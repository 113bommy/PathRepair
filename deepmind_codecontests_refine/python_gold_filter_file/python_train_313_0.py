while True:
 h,w=map(int,input().split())
 if h==0:break
 for i in range(h):print(('#.'*w)[i%2:][:w])
 print()