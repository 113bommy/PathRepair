
m=list(map(int, input().split()))
w=list(map(int, input().split()))
h1, h2=map(int, input().split())
v=[500, 1000, 1500, 2000, 2500]
s = 0
for i in range(5):
    s += max(0.3*v[i], ((1-m[i]/250)*v[i] - (50*w[i])))

print(round(s + h1*100 - h2*50))
