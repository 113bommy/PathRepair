#codeforces_879B_virtual
gi = lambda: list(map(int,input().split()))
n,k = gi()
powers = gi()
if k >= n:
        print(max(powers))
        exit();
wins = 0
while 1:
        if powers[0] > powers[1]:
                wins += 1
                loser = powers.pop(1)
                powers.append(loser)
        else:
                wins = 1
                loser = powers.pop(0)
                powers.append(loser)
        if wins == k:
                print(powers[0])
                exit();