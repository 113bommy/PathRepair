from itertools import chain

T = int(input())
for t in range(T):
    N = int(input())
    ans = input().split(" ")
    a0 = ans[0]
    for i in range(N):
        if ans[i] != a0:
            break
    else:
        print(1)
        print(" ".join("1" for i in range(N)))
        continue
    
    # if there's an even number
    if N%2 == 0:
        print(2)
        print(" ".join("1" if i%2 else "2" for i in range(N)))
    else:
        for i in range(N):
            if ans[i] == ans[(i+1)%N]:
                # then we can "merge" these two
                print(2)
                print(" ".join(chain(("1" if j%2 else "2" for j in range(i+1)), ("2" if j%2 else "1" for j in range(i+1, N)))))
                break
        else:
            print(3)
            print(" ".join("1" if i%2 else "2" for i in range(N-1)) + " 3")




