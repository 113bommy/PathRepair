# https://codeforces.com/contest/1140/problem/D

# when all vertices connect with vertice 1, then the weight is minimum
# weight = 1*2*3 + 1*3*4 + 1*4*5 + ... + 1*(n-1)*n
# 2weight = 6 + 2[3**2 + 4**2 + ... + (n-1)**2 ] + (n-1)*n
# simplify: weight = n(n+1)(n-1)/3 - 2


def main():
    n = int(input())
    print(n*(n+1)*(n-1)//3 - 2)

main()