def find_longest_sequence(number):
    best_length = float('inf')
    curr_solution = []
    used_digits = set()
    groups = find_groups(number)
    for group in groups:
        if group[0] not in used_digits:
            curr_solution.append(group)
            used_digits.add(group[0])
            if len(used_digits) == 3:
                best_length = min(best_length, 2 + curr_solution[1][1])
                used_digits.remove(curr_solution[0][0])
                curr_solution.pop(0)
        else:
            curr_solution.pop(0)
            curr_solution.append(group)
    return 0 if best_length == float('inf') else best_length


def find_groups(number):
    groups = []
    i = 0
    while i < len(number):
        element = number[i]
        count = 0
        while i < len(number) and number[i] == element:
            count += 1
            i += 1
        groups.append((element, count))
    return groups


if __name__ == '__main__':
    numbers = []
    for _ in range(int(input())):
        numbers.append(input())
    for number in numbers:
        print(find_longest_sequence(number))
