n = int(input())
dur = list(map(int, input().split()))
dur_dict = dict()
total = 0
for i in range(n):
  dur[i] = dur[i], i+1
dur.sort(reverse=True)
for i in range(n):
  total += dur[i][0]*i+1
  dur[i] = dur[i][1]
print(total)
print(" ".join(map(str,dur)))
