N,M = map(int, input().split())
citys = [list(map(int,input().split()))+[i] for i in range(M)]

citys.sort(key = lambda x:x[1])
nums = [0]*(N+1)
states = [None]*M

for p,y,i in citys:
    nums[p] += 1
    states[i] = [str(p), str(nums[p])]

for s in states:
    print(s[0].zfill(6)+s[1].zfill(6))
