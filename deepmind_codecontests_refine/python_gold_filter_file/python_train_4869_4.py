def get_type(line):
    total = 0
    count = 0
    was_negative= False
    
    for c in line:
        if c == ')':
            count -= 1
        elif c == '(':
            if count < 0:
                was_negative = True
                total += count
                count = 1
            else:
                count += 1
    if was_negative and count > 0:
        return None
    else:
        return total + count

    
n = int(input().split()[0])
data = {}

for i in range(0, n):
    line = input().strip()
    key = get_type(line)
    if key == None:
        continue
    if key in data:
        data[key] += 1
    else:
        data[key] = 1
        
combinations = 0

for key in data:
    if key > 0:
        continue
    elif -key in data:
        combinations += data[key] * data[-key]
print(combinations)