a = input()
first = 0
second = -1
maximum = 0

for i in range(len(a)):
    if a[i] in "AUIOYE":
        first = second
        second = i
        if maximum <= second - first:
            maximum = second - first
    elif i == len(a)-1:
        first = second
        second = i + 1
        if maximum <= second - first:
            maximum = second - first
print(maximum)