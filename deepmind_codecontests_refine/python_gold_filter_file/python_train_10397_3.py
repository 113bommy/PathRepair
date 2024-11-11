def dig_check(i,d):
    for k in [int(j) for j in str(i)]:
        if k in d:
            return False
    return True


N,K = input().split()
N = int(N)

d = [int(i) for i in input().split()]

for i in range(100001):
    if i >= N :
        if dig_check(i,d):
            print(i)
            break

