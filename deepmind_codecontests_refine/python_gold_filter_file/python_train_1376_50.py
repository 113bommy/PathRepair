cases = int(input())

for each in range(cases):
    data = str(input())
    split_data = data.split("_")
    suffix = split_data[-1][-1]
    # print(suffix)
    if "o" in suffix:
        print("FILIPINO")
    elif "a" in suffix:
        print("KOREAN")
    else:
        print("JAPANESE")