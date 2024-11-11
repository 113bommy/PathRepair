n = 5
arrtime = list(map(int , input().split()))[:n]
wrosub = list(map(int,input().split()))[:n]
hs,hw = map(int, input().split())

score = hs*100 - hw*50

arr = [500,1000,1500,2000,2500]
for i in range(0,5):
    c = 0.3*arr[i]
    d = (1-(arrtime[i]/250))*arr[i] - wrosub[i]*50
    score += max(c,d)
print(int(score))