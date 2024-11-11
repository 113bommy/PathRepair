n, m = (int(i) for i in input().split())

bus = 0
bus_count = 0
for i in input().split():
    bus += int(i)
    previous = int(i)
    if bus > m:
        bus_count += 1
        bus = previous
        
print(bus_count + bool(bus))