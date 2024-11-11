N,K = map(int,input().split())
s = str(input())

ans = N - 1 - s.count('RL') - s.count('LR')
print(min( N-1 , ans + 2 * K ))
