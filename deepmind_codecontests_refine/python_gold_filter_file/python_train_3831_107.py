s = input()
t = ["Sunny","Cloudy","Rainy"]

print(t[(t.index(s)+1) % 3])