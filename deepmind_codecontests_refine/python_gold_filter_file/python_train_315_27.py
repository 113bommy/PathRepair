while True:
 h,w=map(int,input().split())
 if h==0:break
 for i in range(h):print(('#.'*76)[i%2:][:w])
 print()