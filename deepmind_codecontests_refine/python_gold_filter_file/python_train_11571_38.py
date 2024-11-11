N_cities, FuelCap = list(map(int, input().split()))

if FuelCap >= N_cities - 1:
    print(N_cities-1)
else:
    n = N_cities - FuelCap
    minCost = FuelCap + (n * (n + 1) / 2) - 1 
    print(int(minCost))
