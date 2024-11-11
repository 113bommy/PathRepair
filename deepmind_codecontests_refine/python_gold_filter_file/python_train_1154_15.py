N, M = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
    
page_turns = [0]*N
names_on_current_page = 0
for i in range(N):
    page_turns[i] = (A[i] + names_on_current_page) // M
    names_on_current_page = (A[i] + names_on_current_page) % M
print(" ".join(map(str,page_turns)))