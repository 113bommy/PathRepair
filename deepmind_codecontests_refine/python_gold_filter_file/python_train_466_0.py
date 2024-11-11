res = 0
c = [500,1000,1500,2000,2500]
a = list(map(int,input().split()))
w = list(map(int,input().split()))
hs,hu = map(int,input().split())
for i in range(5):
    res += max(0.3*c[i],(1-a[i]/250)*c[i]-50*w[i])
print(int(res+hs*100-50*hu))