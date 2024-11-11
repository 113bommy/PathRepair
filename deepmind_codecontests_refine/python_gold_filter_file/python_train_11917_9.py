N=float(input())
v3N=3.*N
sq=(v3N**2-1./27.)**0.5
v1o3=1./3.
L = (v3N+sq)**v1o3 + (v3N-sq)**v1o3 - 1
print(int(L+1e-6))
