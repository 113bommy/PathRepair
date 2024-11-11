def error():
    print("Bad input.");exit()

n,k = list(map(int,input().split()))
a = list(map(int,input().split()))

test = {1:n not in range(1,101),
        2:k not in range(1,101),
        3:n != len(a),
        4:any([i not in range(1,101) for i in a]),
        }
if any(test.values()):
    error()

kol = 1
ra = {key:a.count(key) for key in set(a)}
if max(ra.values()) > k:
    if max(ra.values()) % k == 0:
        kol += max(ra.values()) // k -1
    else:
        kol += max(ra.values()) // k

print(kol*k*len(set(a)) - n)
