S = input()
w = ['Sunny', 'Cloudy', 'Rainy']
print(w[(w.index(S) + 1) % 3])
