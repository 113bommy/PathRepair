N = int(input())
h = list(map(int, input().split()))

DP = [0, abs(h[0]-h[1])]

for i in range(N-2):
  DP += [min((DP[-2] + abs(h[i]-h[i+2])),(DP[-1] + abs(h[i+2]-h[i+1])))]
  
print(DP[-1])