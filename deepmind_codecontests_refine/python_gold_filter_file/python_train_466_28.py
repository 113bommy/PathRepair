time = list(map(int, input().split()))
wrong = list(map(int, input().split()))
hack = list(map(int, input().split()))
points = [500, 1000, 1500, 2000, 2500]
score = 0

for i in range(5):
    score += max( 0.3*points[i], (1-time[i]/250)*points[i] - wrong[i]*50 )
score = score + hack[0]*100 - hack[1]*50
print(int(score))