n,r1,r2,r3,D = map(int,input().split())

state = [0,0] # after odd number of 2 (1st), or not (2nd)

a = list(map(int,input().split()))

# First element

# Choosing P~P + A

state[0] = r1 * a[0] + r3

# Choosing L + P later or all P

state[1] = min(r2 + r1 + D, r1 * (a[0] + 2) + D)

# Second to Second Last element

for i in range(1,n-1):
    newState = [-1,-1]
    newState[0] = min(state[1] + D + r1 * a[i] + r3, state[0] + r1 * a[i] + r3,
                        state[1] + r2 + r1 + D, state[1] + r1 * (a[i] + 2) + D)
    newState[1] = min(state[0] + r2 + r1 + D, state[0] + r1 * (a[i] + 2) + D)
    state = newState

# Last Element

ans = min(state[0] + r1 * a[-1] + r3, state[0] + 2 * D + r2 + r1, state[0] + 2 * D + r1 * (a[-1] + 2),
            state[1] + r1 * a[-1] + r3, state[1] + r2 + r1 + D, state[1] + r1 * (a[-1] + 2) + D)

print(ans + D * (n-1))