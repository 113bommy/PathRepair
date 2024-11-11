# import graph_plotter
n = int(input())

def primes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if not is_prime[i]:
            continue
        for j in range(i * 2, n + 1, i):
            is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

prime2000 = primes(2000)

edge = [(n, 1)]
for i in range(1, n):
    edge.append((i, i+1))
edge_num = len(edge) 
base = 1
while edge_num not in prime2000:
    edge.append((base, n-base))
    base += 1
    edge_num += 1
print(edge_num)
for a, b in edge:
    print(str(a) + " " + str(b))
# graph_plotter.plot(edge)