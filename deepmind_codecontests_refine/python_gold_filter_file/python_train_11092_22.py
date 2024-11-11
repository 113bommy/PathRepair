n = int(input())
moves = input()
loc   = [int(x) for x in input().split()]
mins = int(10e20)
for  i in range(1, n):
    if moves[i-1] == "R" and moves[i] == "L":
        mins = min(mins, (loc[i] - loc[i-1])//2)
print([-1, mins][mins != int(10e20)])



