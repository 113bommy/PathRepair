ans = 0;
time = list(map(int,input().split()))
tries = list(map(int,input().split()))
ball = [500,1000,1500,2000,2500]
z = list(map(int,input().split()))
gv = z[0]
bv = z[1]
for i in range(0,5):
    ans += max(0.3*ball[i],(1-time[i]/250)*ball[i] - 50*tries[i])
    
    
ans += 100*gv
ans -= 50*bv
print(int(ans))
