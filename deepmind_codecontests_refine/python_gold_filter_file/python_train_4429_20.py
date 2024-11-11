n, c = map(int, input().split())
costs = list(map(int, input().split()))
times = list(map(int, input().split()))
limac = 0
time = 0
for i in range(len(times)):
    time += times[i]
    limac += max(0, costs[i] - c * time)
costs.reverse()
times.reverse()
Radewoosh = 0
time = 0
for i in range(len(times)):
    time += times[i]
    Radewoosh += max(0, costs[i] - c * time)
if limac > Radewoosh:
    print("Limak")
elif limac < Radewoosh:
    print("Radewoosh")
else:
    print("Tie")