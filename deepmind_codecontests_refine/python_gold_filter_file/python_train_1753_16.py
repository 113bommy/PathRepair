k,a,b = (int(i) for i in input().split())
num = k-a
if num<=0: print(1)
elif a<=b: print(-1)
else: print(((num-num%(a-b))//(a-b))*2+2*(min(1,num%(a-b)))+1)