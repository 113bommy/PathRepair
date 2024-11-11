num = input()

def get_poly_by_number(num):
    str_num = str(num)
    return ''.join([str_num, str_num[::-1]])

print(get_poly_by_number(num))