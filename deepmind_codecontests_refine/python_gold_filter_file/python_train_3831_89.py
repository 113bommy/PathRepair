s = ["Sunny", "Cloudy", "Rainy"]
x = input()
print(s[(s.index(x) + 1)%3])