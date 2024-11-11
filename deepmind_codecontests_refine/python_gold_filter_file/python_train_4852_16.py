n,a = map(int,input().split())

angle = (180-(180-(360/n)))/2
jump = (360)/n

c = n
aa = 1
bb = 2
mini = 10e9
if(n==3):
    cc = 3
else:
    for i in range(n,2,-1):
        #print(i,(angle*(n-i+1)))
        boo = abs(a-(angle*(n-i+1)))
        #print(boo)
        mini = min(boo,mini)
        if(mini == boo ):
            cc = i
print(aa,bb,cc)
    

